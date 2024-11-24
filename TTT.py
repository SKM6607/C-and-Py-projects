# Game board
board = [' ' for _ in range(9)]
def print_board():
    """Prints the game board"""
    row1 = '| {} | {} | {} |'.format(board[0], board[1], board[2])
    row2 = '| {} | {} | {} |'.format(board[3], board[4], board[5])
    row3 = '| {} | {} | {} |'.format(board[6], board[7], board[8])

    print()
    print(row1)
    print(row2)
    print(row3)
    print()
def check_win():
    """Checks for a winner"""
    win_conditions = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
    for condition in win_conditions:
        if board[condition[0]] == board[condition[1]] == board[condition[2]] != ' ':                 #Checks if condition of winning is met
            return board[condition[0]] #Returns result
    if ' ' not in board:
        return 'Tie'#If no winning condition and all are filled, then draw
    return False
def game():
    """Tic Tac Toe game"""
    current_player = 'X'
    while True:
        print_board()#Displays board for input
        move = input("Player {}, enter your move (1-9): ".format(current_player))#Asks the user for the position of their current move
        if board[int(move) - 1] == ' ':#After every move checks if the player is entering the valid move
            board[int(move) - 1] = current_player
            result = check_win()#Assigns a value to result
            if result:
                print_board()
                if result == 'Tie':
                    print("It's a tie!")
                else:
                    print("Winner: {}".format(result))
                break
            current_player = 'O' if current_player == 'X' else 'X'#Changes the inputs according to the turns of the users
        else:
            print("Invalid move, try again.")#If Any other input is given
game()#Main function called
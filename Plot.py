import numpy as np#Imports numpy module which takes data in arrays form
import matplotlib.pyplot as plt#Used to plot graph

# Parameters
amplitude = 1.0
frequency = 1.0
phase = 0.0
sample_rate = 100.0
duration = 1.0

# Generate time array
y = np.arange(0, duration, 1/sample_rate)#Gives a list of values incremented by 0.01.

# Generate sine wave
wave = amplitude * np.sin(2 * np.pi * frequency * y + phase)#Gives a list of sin values, which is the x value.

# Plot sine wave
plt.plot(y, wave)#gives the values to graph
plt.xlabel('Time (s)')#Title of the graph x axis
plt.ylabel('sin(x)')#Title of the graph y axis
plt.title('Sine Wave')#Title of the graph
plt.grid(True)#Enable grids, boolean values as arguments
plt.show()#Display graph

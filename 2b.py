import matplotlib.pyplot as plt
n = [1000,3000,6000,10000,15000,20000,25000]
time = [0.000134,0.000442, 0.000956, 0.001668, 0.002665, 0.003652,0.005059]
plt.plot(n, time, marker='o', color='black')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Merge Sort Time vs n')
plt.grid(True)
plt.show()



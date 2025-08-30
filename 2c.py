import matplotlib.pyplot as plt
n = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
time = [0.001441, 0.010001, 0.028182, 0.047659, 0.078468, 0.139747, 0.213696]
plt.plot(n, time, marker='o', color='black')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Insertion Sort Time vs n')
plt.grid(True)
plt.show()
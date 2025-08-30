import matplotlib.pyplot as plt
n = [10,50,100,500,1000,3000,5000,6000,7000]
time = [0.000012,0.000020, 0.000032, 0.000106, 0.000269, 0.000967, 0.001489,0.001926,0.002205]
plt.plot(n, time, marker='o', color='black')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Merge Sort Time vs n')
plt.grid(True)
plt.show()



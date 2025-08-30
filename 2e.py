import matplotlib.pyplot as plt
n = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
time = [0.003393, 0.025266,0.063643,0.153351,0.372289, 0.677883, 1.088778]
plt.plot(n, time, marker='o', color='black')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Bubble Sort Time vs n')
plt.grid(True)
plt.show()
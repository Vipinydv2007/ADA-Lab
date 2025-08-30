import matplotlib.pyplot as plt
n = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
time = [0.002421, 0.016322,0.041844,0.069382,0.142883,0.253269, 0.394183]
plt.plot(n, time, marker='o', color='black')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Selection Sort Time vs n')
plt.grid(True)
plt.show()
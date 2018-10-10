arr = [102, 108, 121, 101, 114, 115]
translated_arr = []

for i in range(len(arr) - 1):
    translated_arr.append(arr[i] & 15)

print(translated_arr)

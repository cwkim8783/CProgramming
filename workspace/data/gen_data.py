# gen_data.py
import math

SIZE = 50000
START = -10 * math.pi
END   =  10 * math.pi
STEP  = (END - START) / (SIZE - 1)

with open("data_2sin20t.txt", "w") as f:
    for i in range(SIZE):
        t = START + i * STEP
        y = 2 * math.sin(20 * t)
        f.write(f"{y}\n")
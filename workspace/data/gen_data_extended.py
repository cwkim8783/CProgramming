"""
Generate data file: data_2sin20t+sin16t-cos35t-3sin(5t-25deg).txt

This follows the same SAMPLE SIZE and t-range conventions as data/gen_data.py.
Run from the data directory: `python gen_data_extended.py`
"""

import math

# Match conventions from data/gen_data.py
SIZE = 50000
START = -10 * math.pi
END = 10 * math.pi
STEP = (END - START) / (SIZE - 1)

OUTPUT = "data_2sin20t+sin16t-cos35t-3sin(5t-25deg).txt"

# Convert 25 degrees to radians for the phase term
PHASE_25_DEG = math.radians(25)

with open(OUTPUT, "w") as f:
    for i in range(SIZE):
        t = START + i * STEP
        y = (
            2 * math.sin(20 * t)
            + math.sin(16 * t)
            - math.cos(35 * t)
            - 3 * math.sin(5 * t - PHASE_25_DEG)
        )
        f.write(f"{y}\n")


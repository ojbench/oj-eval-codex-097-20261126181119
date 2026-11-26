"""Check formatted inputs against a sorting reference."""
import random
import subprocess
import sys

executable = sys.argv[1] if len(sys.argv) > 1 else "./code"
random.seed(2450)


def check(values, rank, text=None):
    if text is None:
        text = f"root = [{', '.join(map(str, values))}], cnt = {rank}\n"
    result = subprocess.run(
        [executable], input=text, text=True, capture_output=True, check=True
    )
    expected = str(sorted(values, reverse=True)[rank - 1])
    assert result.stdout.strip() == expected, (text, expected, result.stdout)


check([12, 5, 18, 2, 9, 15, 20], 4)
check([1], 1)
check([100000], 1)
check([2, 1, 3], 1, "root = [2, 1, 3],\ncnt = 1")
check([2, 3], 2, "root = [2, null, 3], cnt = 2")
for _ in range(300):
    values = random.sample(range(1, 100001), random.randint(1, 1000))
    check(values, random.randint(1, len(values)))
for rank in (1, 50000, 100000):
    check(list(range(1, 100001)), rank)
print("Passed 308 reference checks, including maximum-size inputs.")

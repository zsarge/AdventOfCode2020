f = open("input.txt", "r")
input = f.read()
input = input.split("\n\n")
input = map(lambda str: str.replace("\n", ""), input)

required_fields = [
    "byr",
    "iyr",
    "eyr",
    "hgt",
    "hcl",
    "ecl",
    "pid",
    "cid",
]

def check_passport(passport):
    result = 0
    for field in required_fields:
        result += (field in passport)
    return result >= len(required_fields)

total = 0
for passport in input:
    total += check_passport(passport)

print("Valid passports:")
print(total)
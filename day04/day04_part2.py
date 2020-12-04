import re

f = open("input.txt", "r")
# f = open("test_input.txt", "r")
input = f.read()
# print(input)
input = input.split("\n\n")
input = map(lambda str: str.replace("\n", " "), input)

eye_color = [
    "amb",
    "blu",
    "brn",
    "gry",
    "grn",
    "hzl",
    "oth"
]

def test_string(string: str, min: int, max: int) -> bool:
    return (int(string) >= min and int(string) <= max)

def valid_byr(content: str) -> bool:
    return (len(content) == 4 and test_string(content, 1920, 2002))

def valid_iyr(content: str) -> bool:
    return (len(content) == 4 and test_string(content, 2010, 2020))

def valid_eyr(content: str) -> bool:
    return (len(content) == 4 and test_string(content, 2020, 2030))

def valid_hgt(content: str) -> bool:
    if content[-2:] == "cm":
        return test_string(content[:-2], 150, 193)
    if content[-2:] == "cm":
        return test_string(content[:-2], 59, 76)
    return False

def valid_hcl(content: str) -> bool:
    return bool(re.match('#([0-9]|[a-f]){6}$', content))

def valid_ecl(content: str) -> bool:
    total = 0
    for color in eye_color:
        total += (color in content)
    return (total == 1)

def valid_pid(content: str) -> bool:
        return (len(content) == 9 and content.isdigit())

def valid_cid(content: str) -> False:
    return False

required_fields = {
    "byr": valid_byr,
    "iyr": valid_iyr,
    "eyr": valid_eyr,
    "hgt": valid_hgt,
    "hcl": valid_hcl,
    "ecl": valid_ecl,
    "pid": valid_pid,
    "cid": valid_cid
}

total = 0
for passport in input:
    pass_fields = passport.split(" ")
    print(f"\n{passport}")

    valid_fields = 0
    for field in pass_fields:
        if len(field) <= 0:
            break
        tag = field[:3]
        print(f"Tag: {tag} - {required_fields[tag](field[4:])}")
        if required_fields[tag](field[4:]):
            valid_fields += 1
            
    unique_fields = 0
    for field in required_fields:
        unique_fields += (field in passport)

    # decrement to account for cid
    if (unique_fields >= (len(required_fields) - 1)) and (valid_fields >= (len(required_fields) - 1)):
        print("Entry marked as valid")
        total += 1
    
print()
print("total")
print(total)
# 182 is too high
# 108
# 19 is too low

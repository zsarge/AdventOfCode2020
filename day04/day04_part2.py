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
    if content[-2:] == "in":
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

def valid_cid(content: str) -> True:
    return True

all_fields = {
    "byr": valid_byr,
    "iyr": valid_iyr,
    "eyr": valid_eyr,
    "hgt": valid_hgt,
    "hcl": valid_hcl,
    "ecl": valid_ecl,
    "pid": valid_pid,
    "cid": valid_cid
}

# all_fields[tag](field[4:])
def valid_field(name: str, content: str) -> bool:
    return all_fields[name](content)

required_fields = [
    "byr",
    "iyr",
    "eyr",
    "hgt",
    "hcl",
    "ecl",
    "pid",
]

total = 0
for passport in input:
    passport_fields = passport.split(" ")
    print(f"\n{passport}")

    valid_fields = []
    for field in passport_fields:
        tag = field[:3]
        print(f"Tag: {tag} - Content: {field[4:]}\t- {valid_field(tag, field[4:])}")
        valid_fields.append(valid_field(tag, field[4:]))
            
    print()
    unique_fields = []
    for field in required_fields:
        result = False
        if passport.count(field) == 1:
            result = True 
        unique_fields.append(result)
        print(f"{field} in passport - {result}")
    print()

    # decrement to account for cid
    # if (unique_fields >= (len(all_fields) - 1)) and (valid_fields >= (len(all_fields) - 1)):
    # if (False not in unique_fields) and (False not in valid_fields):
    if False not in valid_fields and False not in unique_fields:
        print("Entry marked as valid")
        total += 1
    else:
        print("NOT VALID")
        print(f"False not in unique_fields: {False not in unique_fields} - False not in valid_fields: {False not in valid_fields}")
    print("\n------")
    
print()
print("total")
print(total)
if total >= 182 or total <= 19 or total == 49 or total == 108 or total == 145:
    print("WRONG ANSWER")

# 190 is too high
# 182 is too high
# 108 is also wrong
# 145 is also wrong
#  49 is also wrong
#  19 is too low

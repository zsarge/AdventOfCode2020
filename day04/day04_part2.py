import re

f = open("input.txt", "r")
input = f.read()
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

    valid_fields = []
    for field in passport_fields:
        tag = field[:3]
        valid_fields.append(valid_field(tag, field[4:]))
            
    unique_fields = []
    for field in required_fields:
        result = False
        if passport.count(field) == 1:
            result = True 
        unique_fields.append(result)

    if False not in valid_fields and False not in unique_fields:
        total += 1
    
print("Valid passports:")
print(total)

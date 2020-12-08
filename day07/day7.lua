
function read_lines(path) 
	local file = io.open(path, "rb") 
	if not file then return {} end
	file:close()
	lines = {}
	for line in io.lines(path) do 
		lines[#lines + 1] = line
	end

	return lines
end

local lines = read_lines('input.txt')

-- print all line numbers and their contents
--
--[[ 

function find_bags_containing(bag) {

	return find_bags_containing(bag) 
	-- use explicit return for tail recursive support
}

find_bags_containing({"shiny gold bag"})
	returns find_bags_containing({"muted yellow bag", "bright white bag"}) 

OR:

queue structure:


]]--



for k,v in pairs(lines) do
	print('line[' .. k .. ']', v)
end

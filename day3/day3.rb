# advent of code, day 3, part 1
# https://adventofcode.com/2020/day/3
# using ruby 2.5.1
# by Zack Sargent
require_relative "input"

class Map
  # Asssume we are on a repeating plane
  def self.getCharAt(x, y)
    height = Input.variable.length()
    if y >= height
      return nil
    end

    width = Input.variable[y].length
    if x <= width
      return Input.variable[y][x]
    elsif x > width # recursively find location on map
      x %= width
      return self.getCharAt(x, y)
    else
      return nil
    end
  end

  def self.isTree(char)
    return char == "#" ? 1 : 0
  end
end

class Toboggan
  def self.travelAtSlope(xSlope, ySlope)
    xPos = 0
    yPos = 0
    char = Map.getCharAt(xPos, yPos)
    path = []
    while yPos < Input.variable.length()
      path.append(char)
      xPos += xSlope
      yPos += ySlope
      char = Map.getCharAt(xPos, yPos)
    end
    return path
  end

  def self.countTrees(array)
    count = 0
    array.each { |char|
      count += Map.isTree(char)
    }
    return count
  end
end

# puts Input.variable

puts Toboggan.countTrees(Toboggan.travelAtSlope(3, 1))

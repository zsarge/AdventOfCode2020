require_relative "input"

class Map
  # Asssume we are on a repeating plane
  def self.charAt(x, y)
    width = Input.variable[y].length
    if x <= width
      return Input.variable[y][x]
    elsif x > width # recursively find location on map
      x -= width
      return self.charAt(x, y)
    else
      return nil
    end
  end

  def self.isTree(char)
    return (char == "#" ? 1 : 0)
  end
end

class Toboggan
  def self.travelAtSlope(x, y)
    xPos = 0
    yPos = 0
    char = Map.charAt(xPos, yPos)
    path = []
    while char
      path.append(char)
      xPos += (x + 1)
      yPos += y
      char = Map.charAt(xPos, yPos)
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

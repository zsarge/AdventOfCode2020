<?php
/* 
 * advent of code, day 6, part 2
 * https://adventofcode.com/2020/day/6
 * using PHP 7.2.24
 * by Zack Sargent
 *
 * Note: this is my first time using PHP.
 */

function getInput() 
{
	$filename = "input.txt";
	// $filename = "test_input.txt";

	$resource = fopen($filename, "r");
	$input_file = fread($resource, filesize($filename));

	$input_file = rtrim($input_file, "\n");
	$raw_array = explode("\n\n", $input_file);

	fclose($resource);
	return $raw_array;
}

function getNumberOfQuestionsEveryoneAnswered($group) {
	$people = explode("\n", $group);
	$characters = str_split($group);

	$questions = array();
	
	// for each character, make sure the number
	// of occurences of that character is equal 
	// to the number of people.
	foreach($characters as $char) {
		$occurences = substr_count($group, $char);	
		if ($occurences == count($people)) {
			$questions[$char] = true;
		}
	}

	// use array for deduplication
	return count($questions);
}

$groups = getInput();
$total = 0;

foreach ($groups as $group) {
	$total += getNumberOfQuestionsEveryoneAnswered($group);
}

echo "Total questions everyone answered:\n";
echo $total , "\n";

?>

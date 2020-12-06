<?php
/* 
 * advent of code, day 6, part 1
 * https://adventofcode.com/2020/day/6
 * using PHP 7.2.24
 * by Zack Sargent
 */

function replace($s) 
{
	return str_replace("\n","", $s);
}

function getInput() {
	// $filename = "input.txt";
	$filename = "test_input.txt";

	$resource = fopen($filename, "r");
	$input_file = fread($resource, filesize($filename));

	$raw_array = explode("\n\n", $input_file);

	$formatted_array  = array_map('replace', $raw_array);

	fclose($resource);
	return $formatted_array;
}

var_dump(getInput());
?>

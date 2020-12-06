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

// function includes($string, $char) {
	// // use if statement to make int
	// // instead of returning directly
	// if (strpos($form, $char) === false) {
		// return 0;
	// } else {
		// return 1;
	// }
// }

function getNumberOfQuestionsEveryoneAnswered($group) {
	// $letters = str_split($str);
	// $answered = array();

	// foreach ($letters as $char) {
	// $answered[$char] = true;
	// }
	// return count($answered);

	// steps:
	// get number of forms in group
	// for each character in each form, make sure the number of occurences in that character is equal to the number of groups


	$people = explode("\n", $group);
	$array = str_split($group);

	// echo "-----------\n";
	// echo "number of people \n";
	// echo count($people), "\n";
	// echo "group: \n";
	// var_dump($group);
	// echo "group: \n";
	// var_dump($array);
	// echo "forms: \n";
	// var_dump($forms);
	// echo "\n";

	$questions = array();
	
	foreach($array as $char) {
		// echo "substr count: $char \n";
		// echo substr_count($group, $char), "\n";
		$occurences = substr_count($group, $char);	
		if ($occurences == count($people)) {
			$questions[$char] = true;
		}
	}

	// echo "questions \n:";
	// var_dump($questions);
	return count($questions);


	// foreach ($forms as $form) {
	// foreach($form as $char) {

	// }
	// }

	// $alpha = range('a', 'z');
	// $alpha = array_fill_keys($alpha, true);

	// foreach ($group as $form) {
	// foreach ($alpha as $char => $value) {
	// // If a char is not found in the form,
	// if (strpos($form, $char) === false) {
	// // mark it false
	// $alpha[$char] = false;
	// }
	// }
	// }

	// // echo "Number of questions everone answered:\n";
	// return count(array_filter($alpha));
}

$groups = getInput();
$total = 0;

foreach ($groups as $group) {
	// echo "NumberOfQuestionsEveryoneAnswered\n";
	// echo getNumberOfQuestionsEveryoneAnswered($group), "\n";
	$total += getNumberOfQuestionsEveryoneAnswered($group);
}


echo "Total questions everyone answered:\n";
echo $total , "\n";

//
// $input = getInput();
// $total = 0;

// foreach ($input as $value) {
// $total += getNumberOfQuestions($value);
// }

// echo "Total questions:\n";
// echo $total , "\n";

?>

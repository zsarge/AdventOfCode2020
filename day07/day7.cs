using System;
using System.IO;
using System.Collections.Generic;
using System.Text.RegularExpressions;
 
/* 
 * Advent of Code: day 7, part 1
 * https://adventofcode.com/2020/day/7
 * using C#, compiled with mono 4.6.2
 * by Zack Sargent
 *
 * Plan: 
 * 	Represent all bags as objects.
 * 	Parse the list into bags that can contain things
 * 	Search for all the bags that can contain a shiny gold bag
 * 	Search for all the bags that could contain that bag.
 * 		Repeat
 * OR?
 * 	Append to object that can contain it?
 * 		Repeat
 * 	Count size of array?
 *
 * 	Look into arrays of objects in C#
 * 		Is there anything like JS arrays?
 */

namespace Day7 {
	class BaggageHandler {
		public struct Bag 
		{
			public string Name;
			public string Contains;
			public Bag(string name, string contains)
			{
				Name = name;
				Contains = contains;
			}
		}

		private static string input;
		private static List<Bag> queue = new List<Bag>();

		public BaggageHandler() 
		{
			input = File.ReadAllText("input.txt");
			// input = File.ReadAllText("test_input.txt");
		}

		private void GetBagsContaining(string bagName) 
		// private List<string> GetBagsContaining(string bagName) 
		{
			// var regex = new Regex(@"^.*contain [1-9] {bagName}.*$");

			// regex.Matches(input)[0]
			// foreach (Match match in regex.Matches(input))
			// Console.WriteLine("Found '{0}' at position {1}", 
			// match.Value, match.Index);
			var regex = new Regex(@"^.*contain [1-9] shiny gold bags.*$", RegexOptions.Multiline);
			// Regex regex = new Regex(@"bag", RegexOptions.Multiline);
			Console.WriteLine("Ran:");
			MatchCollection matches = regex.Matches(input);
			// MatchCollection matches = regex.Matches(input, new Regex("^.*bag.*$", RegexOptions.Multiline));
			foreach (Match match in matches)
			{
				foreach (Capture capture in match.Captures)
				{
					Console.WriteLine("Found:");
					Console.WriteLine("Index={0}, Value={1}", capture.Index, capture.Value);
				}
			}
		}

		// Use list as queue to work through bags
		public List<Bag> GetNumberOfBagsWith(string bagName) 
		{
			queue.Add(new Bag(bagName, "no other bags"));
			// Console.WriteLine(input);

			GetBagsContaining(queue[0].Name);

			Console.WriteLine("Count = ");
			Console.WriteLine(queue.Count);
			// while (queue.Count >= 1) {
			// // note: save all append calculations for last or save pos in memory

			// }
			return queue;
		}
	}

	class Runner {
		// public static 
		public static void Main() 
		{
			BaggageHandler John = new BaggageHandler();
			Console.WriteLine(John.GetNumberOfBagsWith("shiny gold bag")[0].Name);
		}
	}
}

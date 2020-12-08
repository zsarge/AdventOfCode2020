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
		private static double numberOfBags;
		private static string usedBags = "";

		public BaggageHandler() 
		{
			input = File.ReadAllText("input.txt");
			// input = File.ReadAllText("test_input.txt");
		}

		private Bag CreateBagFromRule(string rule) 
		{
			int end = rule.IndexOf("s contain");
			Bag newBag = new Bag(rule.Substring(0, end), "none");

			// Console.WriteLine("Create bag:");
			// Console.WriteLine(newBag.Name);
			// Console.WriteLine("");

			return newBag;
		}

		private void AddBag(Bag bag) {
			queue.Add(bag);
			numberOfBags++;
			usedBags += $"{bag.Name}, ";
		}

		private void AddBagsContaining(string bagName) 
		{
			var regex = new Regex($"^.*contain.*[1-9] {bagName}.*$", RegexOptions.Multiline);
			MatchCollection matches = regex.Matches(input);
			foreach (Match match in matches)
			{
				foreach (Capture capture in match.Captures)
				{
					var name = capture.Value;
					Console.WriteLine($"Used bags = {usedBags}");
					
					Bag bag = CreateBagFromRule(name);
					if (usedBags.IndexOf(bag.Name) == -1) {
						// Console.WriteLine($"IndexOf = {usedBags.IndexOf(name)}");
						// Console.WriteLine($"used '{name}'");
						// AddBag(CreateBagFromRule(name));
						AddBag(bag);
					} else {
						Console.WriteLine($"skipped {bag.Name}\n");
					}
				}
			}
		}

		// Use list as queue to work through bags
		public double GetNumberOfBagsWith(string bagName) 
		{
			queue.Add(new Bag(bagName, "no other bags"));

			AddBagsContaining(queue[0].Name);


			while (queue.Count > 1) {
				// Console.WriteLine($"queue at count {queue.Count} ="); 
				// foreach (var item in queue) 
				// {
					// Console.Write(" ");
					// Console.Write(item.Name); 
				// }
				// Console.WriteLine(""); 
				var index = queue.Count - 1;
				// Console.WriteLine("Count = ");
				// Console.WriteLine(queue.Count);
				// Console.WriteLine(queue[index].Name);
				// Console.WriteLine("");
				// note: save all append calculations for last or save pos in memory
				AddBagsContaining(queue[index].Name);
				queue.RemoveAt(index);
			}
			return numberOfBags;
		}
	}

	class Runner {
		// public static 
		public static void Main() 
		{
			BaggageHandler handler = new BaggageHandler();
			Console.WriteLine(handler.GetNumberOfBagsWith("shiny gold bag"));
		}
	}
}

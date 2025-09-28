using System;
using System.Timers;

class BombDefusalGame
{
    static string secretWord = "silver";  // Changeable secret word
    static char[] displayWord;
    static bool defused = false;
    static bool exploded = false;
    static System.Timers.Timer countdownTimer;
    static int timeLeft = 30; // 30 or 60 seconds

    static void Main()
    {
        Console.WriteLine(" Welcome to the Bomb Defusal Game!");
        Console.WriteLine("You have 30 seconds to guess the secret word.");
        Console.WriteLine("Each incorrect guess will only reveal letters that are correct.");
        Console.WriteLine("Good luck!\n");

        // Initialize display word
        displayWord = new string('_', secretWord.Length).ToCharArray();

        // Set up timer
        countdownTimer = new Timer(1000); // 1 second tick
        countdownTimer.Elapsed += Countdown;
        countdownTimer.Start();

        // Start input loop
        while (!defused && !exploded)
        {
            if (exploded) break; // Ensure that game doesn't continue once time is up

            Console.Write("Guess the word: ");
            string input = Console.ReadLine()?.ToLower();

            if (input == secretWord)
            {
                defused = true;
                break; // Exit if the word is guessed correctly
            }

            UpdateDisplay(input); // Update the displayed word
            Console.WriteLine("Current progress: " + new string(displayWord));
        }

        countdownTimer.Stop(); // Stop the timer once game ends

        // Game outcome
        if (defused)
        {
            Console.WriteLine("\n Congratulations! You defused the bomb!");
        }
        else if (exploded)
        {
            Console.WriteLine("\n Boom! The bomb exploded.");
            Console.WriteLine("The word was: " + secretWord);
        }
        Console.ReadLine();
    }

    static void Countdown(object sender, ElapsedEventArgs e)
    {
        timeLeft--;

        Console.Title = $"Time Left: {timeLeft} sec";

        if (timeLeft <= 0)
        {
            exploded = true;
            countdownTimer.Stop(); // Stop the timer once it reaches zero
            Console.WriteLine("\n\n Time's up! The bomb exploded!");
        }
    }

    static void UpdateDisplay(string input)
    {
        // Reveal letters that are correct and in correct positions
        int len = Math.Min(secretWord.Length, input.Length);

        for (int i = 0; i < len; i++)
        {
            if (input[i] == secretWord[i])
            {
                displayWord[i] = secretWord[i];
            }
        }
    }
}


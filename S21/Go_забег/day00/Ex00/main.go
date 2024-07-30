package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"flag"
)

func main() {
	meanFlag := flag.Bool("mean", true, "Calculate Mean")
	medianFlag := flag.Bool("median", true, "Calculate Median")
	modeFlag := flag.Bool("mode", true, "Calculate Mode")
	sdFlag := flag.Bool("sd", true, "Calculate Standard Deviation")
	flag.Parse()

	numbers := readNumbers()
	if len(numbers) == 0 {
		fmt.Fprintln(os.Stderr, "No numbers provided.")
		os.Exit(1)
	}

	sort.Ints(numbers)

	mean, median, mode, sd := calculateStats(numbers)

	printStats(mean, median, mode, sd, meanFlag, medianFlag, modeFlag, sdFlag)
}

func readNumbers() []int {
	scanner := bufio.NewScanner(os.Stdin)
	var numbers []int
	for scanner.Scan() {
		line := scanner.Text()
		number, err := strconv.Atoi(line)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Invalid input incorrect in line %s\nInput must be integer\n", line)
			os.Exit(1)
		}
		if number < -100000 || number > 100000 {
			fmt.Fprintf(os.Stderr, "Number out of range: %d\nInput must be -100000 < x < 100000\n", number)
			os.Exit(1)
		}
		numbers = append(numbers, number)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintf(os.Stderr, "Error reading input: %v\n", err)
		os.Exit(1)
	}
	return numbers
}

func calculateStats(numbers []int) (float64, float64, int, float64) {
	mean := calculateMean(numbers)
	median := calculateMedian(numbers)
	mode := calculateMode(numbers)
	sd := calculateStandardDeviation(numbers, mean)
	return mean, median, mode, sd
}

func printStats(mean, median float64, mode int, sd float64, 
	meanFlag, medianFlag, modeFlag, sdFlag *bool) {
	if *meanFlag {
		fmt.Printf("Mean: %.2f\n", mean)
	}
	if *medianFlag {
		fmt.Printf("Median: %.2f\n", median)
	}
	if *modeFlag {
		fmt.Printf("Mode: %d\n", mode)
	}
	if *sdFlag {
		fmt.Printf("SD: %.2f\n", sd)
	}
}
package main

import (
	"math"
)

func calculateMean(numbers []int) float64 {
	sum := 0
	for _, number := range numbers {
		sum += number
	}
	return float64(sum) / float64(len(numbers))
}

func calculateMedian(numbers []int) float64 {
	n := len(numbers)
	if n%2 == 0 {
		return float64(numbers[n/2-1]+numbers[n/2]) / 2.0
	}
	return float64(numbers[n/2])
}

func calculateMode(numbers []int) int {
	frequency := make(map[int]int)
	maxFreq := 0
	mode := numbers[0]

	for _, number := range numbers {
		frequency[number]++
		if frequency[number] > maxFreq || (frequency[number] == maxFreq && number < mode) {
			maxFreq = frequency[number]
			mode = number
		}
	}
	return mode
}

func calculateStandardDeviation(numbers []int, mean float64) float64 {
	variance := 0.0
	for _, number := range numbers {
		variance += math.Pow(float64(number)-mean, 2)
	}
	return math.Sqrt(variance / float64(len(numbers)))
}

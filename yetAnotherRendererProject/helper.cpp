template <typename T>
T clamp(T value, T min, T max) {
	if (value > max) {
		return max;
	}
	else if (value < min) {
		return min;
	}
	else {
		return value;
	}
}
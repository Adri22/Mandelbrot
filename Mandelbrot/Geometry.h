#pragma once

struct Dimension {
	int width, height;
};

struct Point {
	float x, y;
};

struct Line {

public:
	Line(float xStart, float yStart, float xEnd, float yEnd) {
		start = {xStart, yStart};
		end = {xEnd, yEnd};
	}

	Point GetStartPoint() {
		return start;
	}

	Point GetEndPoint() {
		return end;
	}

private:
	Point start, end;
};
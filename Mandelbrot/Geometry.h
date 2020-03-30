#pragma once

struct Dimension {
	int width, height;
};

struct Point {
	double x, y;
};

struct Line {

public:
	Line(double xStart, double yStart, double xEnd, double yEnd) {
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
#pragma once

struct Dimension {
	int width, height;
};

struct Point {
	int x, y;
};

struct Line {

public:
	Line(int xStart, int yStart, int xEnd, int yEnd) {
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
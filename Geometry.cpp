
*----------------------------------------------------------------------*
Circle
struct Circle {
    Point center;
    double radius;
    Circle(Point center, double radius) : center(center), radius(radius) {}
};
double circleCircumference(double radius) {
    return 2 * M_PI * radius;
}
double circleArea(double radius) {
    return M_PI * radius * radius;
}
bool isCircleInsideCircle(const Point &innerCenter, double innerRadius, const Point &outerCenter, double outerRadius) {
    double dist = sqrt(pow(innerCenter.x - outerCenter.x, 2) + pow(innerCenter.y - outerCenter.y, 2));
    return (dist + innerRadius) <= outerRadius;
}
bool doesCircleIntersectRectangle(const Circle &circle, const Point &rectTopLeft, double rectWidth, double rectHeight) {//التحقق من تداخل دائرة ومستطيل
    double distance = distanceCircleToRectangle(circle, rectTopLeft, rectWidth, rectHeight);
    return distance < 0;
}
double distanceBetweenCenters(const Circle &c1, const Circle &c2) {// مركزين
    return sqrt(pow(c1.center.x - c2.center.x, 2) + pow(c1.center.y - c2.center.y, 2));
}
double distanceBetweenCircles(const Circle &c1, const Circle &c2) {//دايرتين
    double centerDist = distanceBetweenCenters(c1, c2);
    double radiusDiff = fabs(c1.radius - c2.radius);
    return centerDist - (c1.radius + c2.radius);
}
double distanceCircleToRectangle(const Circle &circle, const Point &rectTopLeft, double rectWidth, double rectHeight) {
    double closestX = std::max(rectTopLeft.x, std::min(circle.center.x, rectTopLeft.x + rectWidth));
    double closestY = std::max(rectTopLeft.y, std::min(circle.center.y, rectTopLeft.y + rectHeight));
    double dx = circle.center.x - closestX;
    double dy = circle.center.y - closestY;
    return sqrt(dx * dx + dy * dy) - circle.radius;
}
double circleIntersectionArea(const Circle &c1, const Circle &c2) {//مساحه تداخل دائرتين
    double d = distanceBetweenCenters(c1, c2);
    if (d >= c1.radius + c2.radius) return 0;
    if (d <= fabs(c1.radius - c2.radius)) return M_PI * pow(std::min(c1.radius, c2.radius), 2);

    double r1 = c1.radius, r2 = c2.radius;
    double a1 = pow(r1, 2), a2 = pow(r2, 2);
    double d2 = pow(d, 2);

    double part1 = a1 * acos((d2 + a1 - a2) / (2 * d * r1));
    double part2 = a2 * acos((d2 + a2 - a1) / (2 * d * r2));
    double part3 = 0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));

    return part1 + part2 - part3;
}
bool is_point_in_circle(Circle c, Point p) {
    return distance(c.center, p) < c.radius;
}
Circle circle_from_two_points(Point p1, Point p2) {
    Point center((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    double radius = distance(p1, center);
    return Circle(center, radius);
}
bool do_circle_and_polygon_intersect(Circle c, const vector<Point>& polygon) {
    for (int i = 0; i < polygon.size(); ++i) {
        Point a = polygon[i], b = polygon[(i + 1) % polygon.size()];
        if (distance_point_to_line(c.center, Line(b.y - a.y, a.x - b.x, -(a.x * b.y - a.y * b.x))) <= c.radius) {
            return true;
        }
    }
    return false;
}

vector<Point> circle_tangent_points(Circle c, Point p) {
    vector<Point> tangents;
    double d = distance(c.center, p);
    if (d < c.radius) return tangents; // النقطة داخل الدائرة

    double l = sqrt(d*d - c.radius*c.radius);
    double angle = atan2(p.y - c.center.y, p.x - c.center.x);
    double offset = acos(c.radius / d);

    tangents.push_back(Point(c.center.x + c.radius * cos(angle + offset), c.center.y + c.radius * sin(angle + offset)));
    tangents.push_back(Point(c.center.x + c.radius * cos(angle - offset), c.center.y + c.radius * sin(angle - offset)));
    
    return tangents;
}
vector<Point> circle_intersection(Circle c1, Circle c2) {
    vector<Point> intersections;
    double d = distance(c1.center, c2.center);
    if (d > c1.radius + c2.radius || d < fabs(c1.radius - c2.radius)) return intersections;

    double a = (c1.radius * c1.radius - c2.radius * c2.radius + d * d) / (2 * d);
    double h = sqrt(c1.radius * c1.radius - a * a);
    Point P = Point(c1.center.x + a * (c2.center.x - c1.center.x) / d, c1.center.y + a * (c2.center.y - c1.center.y) / d);
    intersections.push_back(Point(P.x + h * (c2.center.y - c1.center.y) / d, P.y - h * (c2.center.x - c1.center.x) / d));
    intersections.push_back(Point(P.x - h * (c2.center.y - c1.center.y) / d, P.y + h * (c2.center.x - c1.center.x) / d));
    return intersections;
}
vector<Point> circleLineIntersection(const Point &c, double r, const Point &a, const Point &b) {
    vector<Point> intersections;
    Point ab = b - a;
    Point ac = c - a;
    double A = dot(ab, ab);
    double B = 2 * dot(ac, ab);
    double C = dot(ac, ac) - r * r;
    double D = B * B - 4 * A * C;
    if (D < 0) return intersections; // لا يوجد تقاطع

    D = sqrt(D);
    double t1 = (-B - D) / (2 * A);
    double t2 = (-B + D) / (2 * A);
    if (0 <= t1 && t1 <= 1) intersections.push_back(a + ab * t1);
    if (0 <= t2 && t2 <= 1) intersections.push_back(a + ab * t2);
    return intersections;
}

double sectorArea(double radius, double angle) {
    return 0.5 * radius * radius * angle; // حيث يتم قياس الزاوية بالراديان
}

*----------------------------------------------------------------------*
مضلع
double polygon_perimeter(const vector<Point>& polygon) {
    double perimeter = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        perimeter += distance(polygon[i], polygon[(i+1) % polygon.size()]);
    }
    return perimeter;
}

double polygon_area(const vector<Point>& polygon) {
    double area = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        area += polygon[i].x * polygon[(i+1) % polygon.size()].y - polygon[(i+1) % polygon.size()].x * polygon[i].y;
    }
    return fabs(area) / 2.0;
}
مركز الثقل
Point polygon_centroid(const vector<Point>& polygon) {
    double cx = 0, cy = 0;
    double A = polygon_area(polygon);
    for (int i = 0; i < polygon.size(); ++i) {
        double x0 = polygon[i].x, y0 = polygon[i].y;
        double x1 = polygon[(i + 1) % polygon.size()].x, y1 = polygon[(i + 1) % polygon.size()].y;
        double cross = x0 * y1 - x1 * y0;
        cx += (x0 + x1) * cross;
        cy += (y0 + y1) * cross;
    }
    cx /= (6 * A);
    cy /= (6 * A);
    return Point(cx, cy);
}
 نقطة على محيط مضلع
bool is_point_on_polygon_edge(Point p, const vector<Point>& polygon) {
    for (int i = 0; i < polygon.size(); ++i) {
        Point a = polygon[i], b = polygon[(i + 1) % polygon.size()];
        if (fabs(cross_product(Point(b.x - a.x, b.y - a.y), Point(p.x - a.x, p.y - a.y))) < 1e-9 &&
            p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
            p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y)) {
            return true;
        }
    }
    return false;
}
 أقرب نقطة على مضلع لنقطة معينة
Point closest_point_on_polygon(Point p, const vector<Point>& polygon) {
    Point closest = polygon[0];
    double min_dist = distance(p, closest);
    for (int i = 0; i < polygon.size(); ++i) {
        Point a = polygon[i], b = polygon[(i + 1) % polygon.size()];
        Point c = closest_point_on_line(p, Line(b.y - a.y, a.x - b.x, -(a.x * b.y - a.y * b.x)));
        double dist = distance(p, c);
        if (dist < min_dist) {
            min_dist = dist;
            closest = c;
        }
    }
    return closest;
}

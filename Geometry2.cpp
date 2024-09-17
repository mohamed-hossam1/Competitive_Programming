#define PI acos(-1.0)
#define df(b, a) cout << fixed << setprecision(b) << a << endl; 
template<class T>
istream& operator>> (istream& is, complex<T>& p) {
  T value;
  is >> value;
  p.real(value);
  is >> value;
  p.imag(value);
  return is;
}
#define point complex<double>
#define X real()
#define Y imag()

double toRadians(double degree) {return (degree * PI / 180.0);}
double toDegree(double radian) {if (radian < 0) radian += 2 * PI; return (radian * 180 / PI);}
// vector
double dot(point la,point lb){return (conj(la)*lb).X;}
double cross(point la,point lb){return (conj(la)*lb).Y;}
double distance(point la) {return abs(la);}
double angle(point l1, point l2) {
    double a1 = atan2(l1.Y, l1.X)*180/PI,a2 = atan2(l2.Y, l2.X)*180/PI;
    double a = a2-a1;
    if(a<0) a+=360;
    return a;
}
double angle_withX(point l){
    double a = atan2(l.Y, l.X)*180/PI;
    if(a<0)a+=360;
    return a;
}
point rotate(point lp, double angle) {return polar(1.0,angle)*lp;}
point reflect(point P, point A, point B) {
    point AP = P - A;
    point AB = B - A;
    return conj(AP / AB) * AB + A;
}
double areapolygon(vector<point> p){
    double area = 0;
    for (int i = 1; i < p.size()-1; i++) {
        area += cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return abs(area/2.0);
}

// triangle
double triangleArea(double a, double b, double c)  
{   
    float s = (a + b + c) / 2;  
    return sqrt(s * (s - a) * (s - b) * (s - c));  
}
double fixAngle(double angleA) {return angleA > 1 ? 1 : (angleA < -1 ? -1 : angleA);}
double getSide_A(double b, double angleA, double angleB) {return (sin(angleA) * b) / sin(angleB);}
double getAngle_A1(double a, double b, double angleB) {return asin(fixAngle((a * sin(angleB)) / b));}
double getAngle_A2(double a, double b, double c) {return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));}
string classifyTriangleByAngles(double a, double b, double c) {
    double angleA = getAngle_A2(a, b, c),angleB = getAngle_A2(b, c, a), angleC = getAngle_A2(c, a, b);
    if (fabs(angleA - PI / 2) < 1e-9 || fabs(angleB - PI / 2) < 1e-9 || fabs(angleC - PI / 2) < 1e-9) return "Right";
    if (angleA < PI / 2 && angleB <PI / 2 && angleC < PI / 2) return "Acute";
    return "Obtuse";
}
bool point_in_triangle(point a, point b, point c, point p) {
    double area_orig = areapolygon({a, b, c});
    double area1 = areapolygon({p, b, c});
    double area2 = areapolygon({a, p, c});
    double area3 = areapolygon({a, b, p});
    return fabs(area_orig - (area1 + area2 + area3)) < 1e-9;
}
point centroid(point a,point b,point c) {
    return (a+b+c)/3.0;
}
point orthocenter(const point &a, const point &b, const point &c) {
    double dx1 = b.X - a.X, dy1 = b.Y - a.Y;
    double dx2 = c.X - a.X, dy2 = c.Y - a.Y;
    double dx3 = c.X - b.X, dy3 = c.Y - b.Y;
    double d1 = dx1 * dy2 - dy1 * dx2;
    double d2 = dx1 * dx2 + dy1 * dy2;
    double cx = c.X - (dx1 * dx3 + dy1 * dy3) * dy2 / d2;
    double cy = c.Y + (dx1 * dx3 + dy1 * dy3) * dx2 / d2;
    return point(cx, cy);
}

double inradius(double a, double b, double c) { //نصف قطر الدائرة الداخلية
    double s = (a + b + c) / 2;
    double area = triangleArea(a, b, c);
    return area / s;
}
point circumcenter(const point &a, const point &b, const point &c) {// الخارجيه
    double D = 2 * (a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y));
    double Ux = ((pow(a.X, 2) + pow(a.Y, 2)) * (b.Y - c.Y) +
                 (pow(b.X, 2) + pow(b.Y, 2)) * (c.Y - a.Y) +
                 (pow(c.X, 2) + pow(c.Y, 2)) * (a.Y - b.Y)) / D;
    double Uy = ((pow(a.X, 2) + pow(a.Y, 2)) * (c.X - b.X) +
                 (pow(b.X, 2) + pow(b.Y, 2)) * (a.X - c.X) +
                 (pow(c.X, 2) + pow(c.Y, 2)) * (b.X - a.X)) / D;
    return point(Ux, Uy);
}
Line
point intersection(point a1, point d1, point a2, point d2) {
    double d = cross(d1, d2);
    if (fabs(d) < 1e-9) return {1e18, 1e18}; // الخطان متوازيان
    return (a2 - a1) * cross(d1, d2) / d + a1;
}
double distance_point_to_line(point l1, point l2, point p) {
    return abs(cross(l2 - l1, p - l1)) / abs(l2 - l1);
}


point closest_point_on_line(point p, point l) { //أقرب نقطة على خط إلى نقطة معينة
    point line = l2 - l1;
    double d = dot(p - l1, line) / norm(line);
    return l1 + line * d;

}

// Graham Scan Algorithm
bool polar_compare(const point& a, const point& b, const point& ref) {
    double cross_product = (conj(a - ref) * (b - ref)).imag();
    if (fabs(cross_product) < 1e-9) {
        return abs(a - ref) < abs(b - ref);
    }
    return cross_product > 0; 
}
vector<point> graham_scan(vector<point>& points) {
    point ref = *min_element(points.begin(), points.end(), [](const point& a, const point& b) {
        return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real());
    });

    sort(points.begin(), points.end(), [&](const point& a, const point& b) {
        return polar_compare(a, b, ref);
    });
    vector<point> hull;
    for (const point& p : points) {
        while (hull.size() >= 2) {
            point top = hull.back();
            point second_top = hull[hull.size() - 2];
            if ((conj(top - second_top) * (p - top)).imag() <= 0) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }

    return hull;
}

#define PI acos(-1.0)
#define df(b, a) cout << fixed << setprecision(b) << a << endl; 
#define point complex<double>
#define X real()
#define Y imag()

double toRadians(double degree) {return (degree * PI / 180.0);}
double toDegree(double radian) {if (radian < 0) radian += 2 * PI; return (radian * 180 / PI);}
// vector
double dot(point la,point lb){return (conj(la)*lb).X;}
double cross(point la,point lb){return (conj(la)*lb).Y;}
double distance(point la) {return abs(la);}
double angle(point la,point lb){return atan2(cross(la,lb),dot(la,lb));}//la,lb!=lb,la 
double angle_withX(point la){return atan2(la.X,la.Y);}
point rotate(point lp, double angle) {return polar(1.0,angle)*lp;}
point reflect(point P, point A, point B) //point p over ab 
{
    point Pt = P-A; point Bt = B-A; point Pr = Pt/Bt;
    return conj(Pr)*Bt + A;
}
double areapolygon(vector<point> p){
    double area = 0;
    for (int i = 1; i < p.size()-1; i++) {
        area += cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return abs(area/2.0);
}

// triangle
double fixAngle(double angleA) {return angleA > 1 ? 1 : (angleA < -1 ? -1 : angleA);}
double getSide_A(double b, double angleA, double angleB) {return (sin(angleA) * b) / sin(angleB);}
double getAngle_A1(double a, double b, double angleB) {return asin(fixAngle((a * sin(angleB)) / b));}
double getAngle_A2(double a, double b, double c) {return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));}
string classifyTriangleByAngles(double a, double b, double c) {
    double angleA = getAngle_A2(a, b, c),angleB = getAngle_A2(b, c, a), angleC = getAngle_A2(c, a, b);
    if (fabs(angleA - PI / 2) < 1e-9 || fabs(angleB - PI / 2) < 1e-9 || fabs(angleC - M_PI / 2) < 1e-9)return "Right";
    if (angleA < PI / 2 && angleB <PI / 2 && angleC < PI / 2) return "Acute";
    return "Obtuse";
}

bool is_point_in_triangle(point a, point b, point c, point p) {
    double area_orig = areapolygon({a, b, c});
    double area1 = areapolygon({p, b, c});
    double area2 = areapolygon({a, p, c});
    double area3 = areapolygon({a, b, p});
    return fabs(area_orig - (area1 + area2 + area3)) < 1e-9;
}
point centroid(point a,point b,point c) {
    return (a+b+c)/3.0;
}

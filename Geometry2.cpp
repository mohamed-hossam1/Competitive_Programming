#define PI acos(-1.0)
#define df(b, a) cout << fixed << setprecision(b) << a << endl; 
#define point complex<double>

double toRadians(double degree) {return (degree * PI / 180.0);}
double toDegree(double radian) {if (radian < 0) radian += 2 * PI; return (radian * 180 / PI);}
vector
double dot(point a,point b){return (conj(a)*b).real();}
double cross(point a,point b){return (conj(a)*b).imag();}
double distance(point a) {return abs(a);}
double angle(point a,point b){return atan2(cross(a,b),dot(a,b));}//a,b!=b,a 
double angle_withX(point a){return atan2(a.real(),a.imag());}
point rotate(point p, double angle) {return polar(1.0,angle)*p;}
point reflect(point a, point b) {return (a-b)*(polar(1.0,PI))+(b);}



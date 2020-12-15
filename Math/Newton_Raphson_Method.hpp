double Newton_Raphson_Method(func f,double x=1){
    while(abs(f.setX(x))>0.000001)
      	x-=(f.setX(x)/prime(f).setX(x));
    return x;
}

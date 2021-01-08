inline num abs(num x){
      num y=x>>31;
      return (x+y)^y;
}

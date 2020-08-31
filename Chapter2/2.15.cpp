int ival = 1.01;
int& rval1 = 1.01;      //invalid, cannot refer to literal
int& rval2 = ival;
int& rval3;             //invalid, declared as reference but not intialized
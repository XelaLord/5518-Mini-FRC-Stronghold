float leftSidePower;
float rightSidePower;

void DriveFunction(int x, int y) {
    leftSidePower = (-x*255)+(y*255);
    rightSidePower = (-x*255)+(-y*255);
    
    if(leftSidePower >255){
      leftSidePower = 255;
     }
    else if (leftSidePower < -255){
      leftSidePower = -255;
     }
    if(rightSidePower >255){
      rightSidePower = 255;
     }
    else if (rightSidePower <-255){
      rightSidePower = -255;
     }
    if(leftSidePower < 0){
        DriveMotorL(leftSidePower,true);
      }
    if (leftSidePower>0){ 
        DriveMotorL(leftSidePower,false);
      } 
    if(rightSidePower < 0){
        DriveMotorR(rightSidePower,true);
      }
    if (rightSidePower>0){
        DriveMotorR(rightSidePower,false);
      } 
  }

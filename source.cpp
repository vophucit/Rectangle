//Programer: PHUC VO
//The program can: 1/ CREATE and ROTATE a RECTANGLE from 2 points's coordinates, which are inputed from USER
//                 2/ CREATE and ROTATE a TRIANGLE from 2 points's coordinates, which are inputed from USER

#include <iostream>

using namespace std;


//======================================================================================

//CLASS POINT
class point{
public:
	//Constructor
	point(){
		x = 0;
		y = 0;
	}
	point(int x_axis, int y_axis){
		x = x_axis;
		y = y_axis;
	}

	//Set values
	void setPointAll(point knot){
		x = knot.getXPoint();
		y = knot.getYPoint();
	}
	void setPoint(int x_axis, int y_axis){
		x = x_axis;
		y = y_axis;
	}
	void setXPoint(int x_axis){
		x = x_axis;
	}
	void setYPoint(int y_axis){
		y = y_axis;
	}

	//get values
	int getXPoint(){
		return x;
	}
	int getYPoint(){
		return y;
	}

	//FUCTION Create a Point
	void createPoint(){
		//Enter the coordinate of the point
		cout << "Enter the coordinates of the point: ";
		cin >> x >> y;
	}


private:
	int x;
	int y;
};

//CLASS RECTANGLE
class rectangle{
public:
	//Constructor
	rectangle(){
		pointTL.setPoint(0, 0);
		pointBR.setPoint(10, 10);
	}
	rectangle(point point_TL, point point_BR){
		pointTL.setPointAll(point_TL);
		pointBR.setPointAll(point_BR);
	}

	//Set values
	void setRectangle(point point_TL, point point_BR){
		pointTL.setPointAll(point_TL);
		pointBR.setPointAll(point_BR);
	}
	void setTL_Rectangle(point point_TL){
		pointTL.setPointAll(point_TL);
	}
	void setBR_Rectangle(point point_BR){
		pointBR.setPointAll(point_BR);
	}

	//Get values
	point getTL_Rectangle(){
		return pointTL;
	}
	point getBR_Rectangle(){
		return pointBR;
	}

	void showRect(){
		for (int i = pointTL.getXPoint(); i <= pointBR.getXPoint(); i++){
			for (int j = pointTL.getYPoint(); j <= pointBR.getYPoint(); j++){
				if (i == pointTL.getXPoint() || i == pointBR.getXPoint() || j == pointTL.getYPoint() || j == pointBR.getYPoint()){
					cout << "*" << " ";
				}
				else{
					cout << " " << " ";
				}
			}
			cout << endl;
		}
	}
	void rotateRect(){
		//Variable declarations
		int horizontal, vertical;

		//Change the coordinates of 2 points
		horizontal = pointBR.getXPoint() - pointTL.getXPoint();
		vertical = pointBR.getYPoint() - pointTL.getYPoint();
		pointBR.setXPoint(pointTL.getXPoint() + vertical);
		pointBR.setYPoint(pointTL.getYPoint() + horizontal);
	}

private:
	point pointTL, pointBR;
};

//CLASS TRIANGLE
class triangle{
public:
	//Constructor
	triangle(){
		pointTop.setPoint(10, 10);
		pointRight.setPoint(20, 20);
	}
	triangle(point point_Top, point point_Right){
		pointTop.setPointAll(point_Top);
		pointRight.setPointAll(point_Right);
	}

	//Set values
	void setTriangle(point point_Top, point point_Right){
		pointTop.setPointAll(point_Top);
		pointRight.setPointAll(point_Right);
	}
	void setTTriangle(point point_Top){
		pointTop.setPointAll(point_Top);
	}
	void setRTriangle(point point_Right){
		pointRight.setPointAll(point_Right);
	}

	//Get values
	point getTopTriangle(){
		return pointTop;
	}
	point getRightTriangle(){
		return pointRight;
	}

	//FUNCTION Show a Triangle
	void showTri(){
		if (domain > 4){
			domain -= 4;
		}
		if (domain == 1)//Triangle in the 1st quandratic
		{
			for (int i = 0; i <= pointRight.getXPoint() - pointTop.getXPoint(); i++){
				for (int j = 0; j <= pointRight.getYPoint() - pointTop.getYPoint(); j++){
					if (i == j || i == pointRight.getYPoint() || j == 0){
						cout << "*" << " ";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else if (domain == 2){//Triangle in the 2nd quandratic
			for (int i = 0; i <= pointRight.getXPoint() - pointTop.getXPoint(); i++){
				for (int j = 0; j <= pointRight.getYPoint() - pointTop.getYPoint(); j++){
					if (i + j == pointRight.getYPoint() || i == 0 || j == 0){
						cout << "*" << " ";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else if (domain == 3){//Triangle in the 3rd quandratic
			for (int i = 0; i <= pointRight.getXPoint() - pointTop.getXPoint(); i++){
				for (int j = 0; j <= pointRight.getYPoint() - pointTop.getYPoint(); j++){
					if (i == 0 || i == j || j == pointRight.getYPoint()){
						cout << "*" << " ";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else if (domain == 4){//Triangle in the 4th quandratic
			for (int i = 0; i <= pointRight.getXPoint() - pointTop.getXPoint(); i++){
				for (int j = 0; j <= pointRight.getYPoint() - pointTop.getYPoint(); j++){
					if (i == pointRight.getXPoint() || i + j == pointRight.getYPoint() || j == pointRight.getYPoint()){
						cout << "*" << " ";
					}
					else{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
	}
	//FUNCTION Rotate a Triangle
	void rotate(){//In fact, I only change the number of quadratic to Prompt on the Screen
		domain++;
	}

private:
	point pointTop, pointRight;
	int domain = 1;
};

//=====================================================================================
void instructionInput();
void createRect();
void createTri(point, point);
//=======================================================================================

//FUNCTION Explain to the USER how they can input correctly
void instructionInput()
{
	cout << "\n\nSorry, your points's corrdinates are not correct! Please input again!";
	cout << "\n[x1 < x2] and [y1 < y2]\n\n";
}
//FUNCTION to create RECTANGLE
void createRect(point topLeftPoint, point bottomRightPoint){
	//Object and variable declarations
	rectangle rect;
	int timeRotate = 1;
	char function;
	//Set values to "Triangle Object"
	rect.setRectangle(topLeftPoint, bottomRightPoint);

	cout << endl << endl;
	cout << "RECTANGLE " << (rect.getBR_Rectangle()).getXPoint() - (rect.getTL_Rectangle()).getXPoint() + 1;
	cout << "X" << (rect.getBR_Rectangle()).getYPoint() - (rect.getTL_Rectangle()).getYPoint() + 1 << "\n";
	rect.setRectangle(topLeftPoint, bottomRightPoint);
	rect.showRect();//Call the Function create and prompt a Rectangle
	cout << endl << endl;

	cout << "Do you wanna rotate the Rectangle 90 degree?  [Y] Yes --- [N] No.\nANSWER: ";
	cin >> function;
	if (function == 'Y' || function == 'y'){
		do{
			if (timeRotate % 2 != 0){
				rect.rotateRect();//Call the Function rotate a Rectangle
				cout << "Rotate 90 degree!" << "\n";
				rect.showRect();//Call the Function recreate after rotating and prompt a Rectangle
			}
			else{
				rect.rotateRect();//Call the Function rotate a Rectangle
				cout << "Rotate 90 degree!" << "\n";
				rect.showRect();//Call the Function recreate after rotating and prompt a Rectangle
			}
			timeRotate++;
			cout << "Do you wanna rotate the Rectangle 90 degree?  [Y] Yes --- [N] No.\nANSWER: ";
			cin >> function;
		} while (function == 'Y' || function == 'y');
	}
}
//FUNCTION to create TRIANGLE
void createTri(point topLeftPoint, point bottomRightPoint){
	//Object and vairable declarations
	triangle tri;
	char rotate;
	int timeRotate = 1;
	//Set the value to "Triangle Object"
	tri.setTriangle(topLeftPoint, bottomRightPoint);

	cout << "\nTRIANGLE: \n";
	tri.showTri();//Call the Function to create and prompt a Tritangle
	cout << "\nDo you wanna rotate this Triangle 90 degree?\n\t\t[Y] Yes  --  [N] No\n\n";
	cin >> rotate;
	if (rotate == 'Y' || rotate == 'y'){
		do{
			if (timeRotate > 4){//Reset the "timeRotate" variable to determine which Rotate function should use
				timeRotate -= 4;
			}
			if (timeRotate == 1){
				cout << "\nTRIANGLE after ROTATE 90:\n";
				tri.rotate();
				tri.showTri();//Call the Function to recreate and prompt the Triangle after rotating
			}
			else if (timeRotate == 2){
				cout << "\nTRIANGLE after ROTATE 90:\n";
				tri.rotate();
				tri.showTri();//Call the Function to recreate and prompt the Triangle after rotating
			}
			else if (timeRotate == 3){
				cout << "\nTRIANGLE after ROTATE 90:\n";
				tri.rotate();
				tri.showTri();//Call the Function to recreate and prompt the Triangle after rotating
			}
			else{
				cout << "\nTRIANGLE after ROTATE 90:\n";
				tri.rotate();
				tri.showTri();//Call the Function to recreate and prompt the Triangle after rotating
			}
			cout << "\nDo you wanna go on rotating Triangle 90 degree?  [Y] Yes --  [N] No.\nANSWER: ";
			cin >> rotate;
			timeRotate++;
		} while (rotate == 'Y' || rotate == 'y');
	}
}

//========================================================================================

int main(){
	//Variable declarations
	int x, y;
	point topLeftPoint, bottomRightPoint;
	int function;
	int timeInput = 0;

	//Select the function to do. [1] or [2]
	do{
		if (timeInput != 0){//ONY prompt to the screen when USER input incorrectly
			cout << "\nPlease ONLY enter [1] or [2] in your ANSWER!\n";
		}

		cout << "What function you wanna do?\n\n\t\t\ [1]-Rectangle   [2]-Right Triangle ";
		cout << "\nANSWER: ";
		cin >> function;
		timeInput = 1;
	} while (function != 2 && function != 1);

	timeInput = 0;//Reset the timeInput variable = 0

	//Input the coordinates of 2 points
	do{
		//INPUT RECTANGLE
		if (function == 1){
			if (timeInput != 0){//ONLY prompt to the screen when the USER input incorrectly
				instructionInput();
			}

			cout << "\nCreate the TOP-LEFT. \n";
			topLeftPoint.createPoint();//Call the function to create a point => Top-Left point
			cout << "\nCreate the BOTTOM-RIGHT. \n";
			bottomRightPoint.createPoint();//Call the function to create a point => Bottom-Right point
			timeInput = 1;
		}
		//INPUT RIGHT TRIANGLE
		else{
			if (timeInput != 0){//ONLY prompt to the screen when the USER input incorrectly
				instructionInput();
			}

			do{//Test the INPUT to have a invalid isosceles right triangle
				if (timeInput != 0){//ONLY prompt to the screen when the USER input incorrectly
					cout << "\n===>The lenghts of 2 sides must be EQUAL!\nWhich means [x2-x1]=[y2-y1]\n";
				}
				cout << "\nCreate the TOP-LEFT. \n";
				topLeftPoint.createPoint();
				cout << "\nCreate the BOTTOM-RIGHT. \n";
				bottomRightPoint.createPoint();
				timeInput = 1;
			} while ((bottomRightPoint.getXPoint() - topLeftPoint.getXPoint()) != (bottomRightPoint.getYPoint() - topLeftPoint.getYPoint()));


		}
	} while (topLeftPoint.getXPoint() > bottomRightPoint.getXPoint() != topLeftPoint.getYPoint() > bottomRightPoint.getYPoint());

	//Create and Rotate the RECTANGLE
	if (function == 1){
		createRect(topLeftPoint, bottomRightPoint);
	}
	//Create and Rotate the TRIANGLE
	else{
		createTri(topLeftPoint, bottomRightPoint);
	}
}
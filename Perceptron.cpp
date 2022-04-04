#include <iostream>
#include <time.h>
using namespace std;

class perceptron{
	public:
		float x[4],y[4],o[4],x_w,y_w,threshold;
		int iterations=0,max_iter=100;
    perceptron()
    {   
		for(int i=0;i<4;++i)
    	{
    		cout << "Enter the inputs  x" <<i <<"  and y" <<i  << endl;
    		cin >>x[i]>>y[i];
    		
	    }
		for(int i=0;i<4;++i)
    	{
    		cout << "Enter output " <<i << endl;
    		cin >>o[i];
    		
	    }	    
		// Generating random weights		
	    int min=-1;
	    int max=1;
	    srand ( time(NULL));
	    x_w = rand()%(max-min + 1) + min;
	    y_w = rand()%(max-min + 1) + min;
	    	
		
		
	    cout<<"Enter threshold " <<endl;
	    cin>>threshold;	
	    cout << "Random weight initialised are : " << x_w << " and " << y_w << endl;
		;
	    
	    
			
	}

	int train()
	{   int counter=0; 
		for (int i=0;i<4;++i)
		{
			
			float pred_output=x_w*x[i]+y_w*y[i]-threshold;
			if (pred_output>0)
			{
				pred_output=1;
			}
			else
			{
				pred_output=0;
			}
			
			if (pred_output>0 and o[i]<=0)
			{
				x_w=x_w-x[i];
				y_w=y_w-y[i];
			}
			if (pred_output<=0 and o[i]>0)
			{
				x_w=x_w+x[i];
				y_w=y_w+y[i];
			}
			if (pred_output==o[i])
			{
			  counter=counter+1;
			  if(counter==4)
			  { 
			    cout << "TRAINING COMPLETED SUCCESSFULLY" <<endl;
			  	return 1;
			  }

			  	
			}
			iterations=iterations+1;
			if(iterations==max_iter)
			{
				cout << "ITERATION LIMIT REACHED.TRAINING UNSUCCESSFULL" << endl;
				return 0;
			}
			
		}
		train();
		
	}
	void test()
	{   
		cout << "Weights found by the model are  : " <<x_w << " and " <<y_w<<endl; 
		cout << "TESTING THE MODEL WITH INITIAL DATASET" << endl;
		for (int i=0;i<4;++i)
		{
			float prediction=x_w*x[i]+y_w*y[i]-threshold;
			if (prediction>0)
				prediction=1;
			else
				prediction=0;
			cout << "Prediction : " << prediction << " Actual output : "<< o[i] << endl;
		
					
		}
		cout << "Equation of the decision line : " << x_w << "x+" <<y_w<<"y-"<<threshold<<"=0"<< endl; 
	}
};
int main()
{
	perceptron a;
	int flag=a.train();
	if (flag==1)
	{
	 a.test	();
	}

	
	return 0;
}

/*
This sketch generates a program for implimenting a state machine
using the FiniteStateMachine Library.
user is prompted for stste machine name and up to 10 states
a fully functioining sketch is generated as output.
*/


String stateMachineName ,stateName;
String states[11];
int stateNum;

String getString(String prompt){
    String readString = "";
    //Serial.println("getting string...");
    Serial.println(prompt);
    while (!Serial.available()) {}
        while (Serial.available()) readString = Serial.readStringUntil('\n');
   
    //Serial.println("returning <"+readString +">");
    return readString;
    }
    
String capitalize(String str) {
    String s = char(toupper(char(str[0]))) + str.substring(1, sizeof(str)-1);
    return s;
}

void process() {
    Serial.println(""); Serial.println("GENERATED CODE:"); Serial.println("");
    Serial.println("#include <FiniteStateMachine.h>"); Serial.println("");
    Serial.println("//Forward Declarations"); Serial.println("");
    int n = 1;
    do{
        Serial.println("void enter" + capitalize(states[n]) + "();");
        Serial.println("void update" + capitalize(states[n]) + "();");
        Serial.println("void exit" + capitalize(states[n]) + "();");
        Serial.println("");
        n++;
    } while (states[n] != "#" && n < 10);
    //state declarations
    Serial.println("//State Definitions"); Serial.println("");
    n = 1;
    do {
        Serial.println("State " + capitalize(states[n]) + " = State(enter" + capitalize(states[n])+",update"+ capitalize(states[n]) +",exit" + capitalize(states[n]) + ");");
        n++;
    } while (states[n] != "#" && n < 4);
    Serial.println(""); Serial.println("//State Machine construction"); Serial.println("");
    Serial.println("FiniteStateMachine " + capitalize(stateMachineName) + "= FiniteStateMachine("+capitalize(states[1])+");");
    Serial.println("");
    Serial.println("//State Functions"); Serial.println("");
    n = 1;
    do {
        Serial.println("void enter" + capitalize(states[n]) + "(){\n\n}\n");
        Serial.println("void update" + capitalize(states[n]) + "(){\n\n}\n");
        Serial.println("void exit" + capitalize(states[n]) + "(){\n\n}\n");
        Serial.println("");
        n++;
    } while (states[n] != "#" && n < 4);
    Serial.println("");
    Serial.println("void setup(){\n\n}");
    Serial.println("");
    Serial.println("void loop(){\n"+capitalize(stateMachineName)+".update();\n}");
}

void printStates() {
    Serial.println("PRINTING STATES");
    for (int s = 1; s < 11; s++) {
        Serial.println( (String)s + " " + (String)states[s]);
        //Serial.println(s<<" "<<states[s]);
    }
    Serial.println("DONE PRINTING STATES");
   
}
void setup() {
    Serial.begin(115200);
    delay(2000);

    for (int s = 1; s < 10; s++) states[s] = "";
    //printStates();

    stateMachineName = getString("Enter name of state machine "+ stateNum);
    Serial.println("");
    Serial.println("State Machine " + stateMachineName + " created"); 
    Serial.println("");

    stateNum = 0;
    states[0] = " "; //seed

    do  {
        stateNum++;
        states[stateNum] = getString("enter name of state # " + (String)stateNum);
        Serial.println("");
        Serial.println(states[stateNum] + " created.");
        //printStates();
    } while (states[stateNum] != "#" && stateNum<=10);// end do
    //printStates();
    process();
}

void loop() {

}
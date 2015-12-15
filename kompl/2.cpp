/*
 * A) Förklara vad raden virtual void run() = 0; innebär?
 *
 * Det innebär att det är en "pure virtual function". Vi vet inte hur den ska definieras i basklassen, och vi måste definiera den i subklasserna --> "A pure virtual function implicility makes the class it is defined for abstract". Kan jämföras med abstract class i Java. I praktiken vill man kanske förhindra instansiering av Motor.
 */

class Motor {
    public:
        virtual void run() = 0;
};

int main() {
    Motor m;
}

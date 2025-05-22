#include "Medium.h"

class Magazin : public Medium {
protected:
	Datum datumAusgabe;
	std::string sparte;
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe ,std::string initSparte);

	virtual ~Magazin(void);

	void ausgabe() const override;
};



#include "Medium.h"

class DVD : public Medium {
protected:
	int altersfreigabe;
	std::string genre;
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	virtual ~DVD(void);

	void ausgabe() const override;
};

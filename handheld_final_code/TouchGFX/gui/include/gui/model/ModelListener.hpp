#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <stdint.h>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    //Overrided in MainMenuPresenter.hpp
    virtual void notifyMethaneLevelChanged(uint16_t newMethaneLevel) {}
    virtual void buttonPressed(uint8_t button) {}
    virtual void refreshScreen() {}
    virtual void setFaultLight(bool faultLightStatus) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP

#include "Tree.h"
#include "TEvent.h"

class ConsoleDialog : public Tree
{
protected:
    int _endState;

public:
    ConsoleDialog(void);
    virtual ~ConsoleDialog(void);

    virtual void GetEvent(TEvent& event);
    virtual int Execute();
    virtual void HandleEvent (TEvent& event);
    virtual void ClearEvent(TEvent& event);
    int ValidValue();
    void EndExecuting();
};
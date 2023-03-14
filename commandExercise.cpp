/*Command Coding Exercise
Implement the Account::process()  function to process different account commands. The rules are obvious:

success  indicates whether the operation was successful
You can only withdraw money if you have enough in your account*/

struct Command
{
    enum Action
    {
        deposit,
        withdraw
    } action;
    int amount{0};
    bool success{false};
};

struct Account
{
    int balance{0};

    void process(Command &cmd)
    {
        switch (cmd.action)
        {
        case Command::Action::deposit:
            balance += cmd.amount;
            cmd.success = true;
            break;

        case Command::Action::withdraw:
            if (balance >= cmd.amount)
            {
                balance -= cmd.amount;
                cmd.success = true;
            }
            else
                cmd.success = false;
            break;
        }
        // todo
    }
};
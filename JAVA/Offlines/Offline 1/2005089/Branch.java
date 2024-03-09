public class Branch {

    private int id;
    private String name;
    private Account []  accounts;
    private int accountCount;
	// add your code here
	// you are allowed to add variables here
    // there can be at most 20 branches

    private static int b_count=0;
    private static Branch[] b_array= new Branch [20];

    // you are not allowed to write any other constructor
    public Branch(int id, String name) {
        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        // add your code here
        b_array[b_count++]=this;
    }

	// you are not allowed to modify this method
    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }

    // add your code here


    public double getBranchBalance()
    {
        double sum=0;
        for(int i=0;i<accountCount;i++)
            sum=sum+accounts[i].getAccountBalance();
        return sum;
    }

    public Account getMinBalanceAccount()
    {
        Account minimum= accounts[0];
        for(int i=0; i<accountCount; i++)
        {
            if(accounts[i].getAccountBalance() < minimum.getAccountBalance())
                minimum= accounts[i];
        }
        return minimum;
    }

    public static void transferBalance(Account user1,Account user2,double bal)
    {
        user1.setAccountBalance(user1.getAccountBalance()-bal);
        user2.setAccountBalance(user2.getAccountBalance()+bal);
    }

    public static void printAllBranchesInfo()
    {
        for(int i=0; i<b_count;i++)
        {
            System.out.println("Branch ID : " + (i+1) + " Branch Name : " + b_array[i].name);

            for(int j=0; j<b_array[i].accountCount; j++)
            {
                b_array[i].accounts[j].printAccount();
            }
        }

    }
}

public class Invoice {
    int id;
    Customer customer;
    double amount;

    public Invoice(int id, Customer customer, double amount) {
        this.id = id;
        this.customer = customer;
        this.amount = amount;
    }
	
	// write set and get methods
    public void setId(int id)
    {
        this.id=id;
    }

    public void setCustomer(Customer customer)
    {
        this.customer=customer;
    }

    public void setAmount(double amount)
    {
        this.amount=amount;
    }

    public int getId()
    {
        return id;
    }

    public int getCustomerId()
    {
        return customer.getId();
    }

    public String getCustomerName()
    {
        return customer.getName();
    }

    public double getAmount()
    {
        return amount;
    }

    public int getCustomerDiscount()
    {
        return customer.getDiscount();
    }

    public double getAmountAfterDiscount()
    {
        return amount-customer.getDiscount();
    }
	
	// write other methods to successfully run TestMain 
}

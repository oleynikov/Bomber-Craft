#ifndef AFACTORY_H
#define AFACTORY_H

template <typename Feedstock, typename Product>
class AFactory
{

    public:
                            AFactory(void)
        {

            this->product = NULL;

        }
        void                setup(Feedstock feedstock)
        {

            this->feedstock = feedstock;

        }
        virtual bool        make(void) = 0;
        Product*            getProduct(void) const
        {

            return this->product;

        }

    protected:
        Feedstock           feedstock;
        Product*            product;

};

#endif // AFACTORY_H

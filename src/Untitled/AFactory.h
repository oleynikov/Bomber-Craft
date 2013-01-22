#ifndef AFACTORY_H
#define AFACTORY_H

template <typename Feedstock, typename Product>
class AFactory
{

    public:
        void                setup(Feedstock feedstock)
        {

            this->feedstock = feedstock;

        }
        virtual Product     make(Feedstock feedstock)
        {

            this->setup(feedstock);

            return this->make();

        }
        virtual Product     make(void) = 0;

    protected:
        Feedstock           feedstock;

};

#endif // AFACTORY_H

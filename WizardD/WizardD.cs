using System;
using System.Data.SqlTypes;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Linq;

namespace WizardD
{
    public class Wizard
    {
        Random r = new Random();
        string name;
        int maxHp;
        int maxMana;
        int hp;
        int mana;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public int Hp
        {
            get
            {
                return hp;
            }
            set
            {
                hp = Math.Min(maxHp, Math.Max(0, value));
            }
        
        }
        public int Mana
        {
            get
            {
                return mana;
            }
            set
            {
                mana = Math.Min(maxMana, Math.Max(0, value));
            }
        }
        public int MaxHp
        {
            get
            {
                return maxHp;
            }
            set
            {
                maxHp = value;
            }
        }
        public int MaxMana
        {
            get
            {
                return maxMana;
            }
            set
            {
                maxMana = value;
            }
        }
        public void Attack(Wizard defender)
        {
            defender.hp -= r.Next(10, 20);
            mana -= r.Next(10, 20);
            if (mana < 0) mana = 0;
            if (defender.hp < 0) defender.hp = 0;
        }
        public void Heal(int healpoint)
        {
            hp += healpoint;
            mana -= r.Next(10, 20);
            if (Mana < 0) mana = 0;
            if (hp > maxHp) hp = maxHp;
        }
        public void RegenMana(int manapoint)
        {
            mana += manapoint;
            if (mana > maxMana) mana = maxMana;
        }
        public void CastSpell(int spell)
        {
            mana -= spell;
            if (mana < 0) mana = 0;
        }
        /*
        Лабраторная №4
        |||
        vvv
        */
        public virtual string method()
        {
            Random r = new Random();
            int count = r.Next(1,1000000);
            return $"{count} денег будет у персонажа к концу года";
        }
    }

    public class Necromancer : Wizard //Наследование
    {
        string demonName;
        public string DemonName
        {
            get
            {
                return demonName;
            }
            set
            {
                demonName = value;
            }
        }
        public override string method()
        {
            Random r = new Random();
            int count = r.Next(1, 100);
            return $"{count} лет осталось жить персонаж";
        }
    }

    public class Druid : Wizard
    {
        int druidAge;
        public int DruidAge
        {
            get
            {
                return druidAge;
            }
            set
            {
                druidAge = value;
            }
        }
        public override string method()
        {
            Random r = new Random();
            int count = r.Next(1,5);
            return $"{count} детей будет у персонажа";
        }
    }
}

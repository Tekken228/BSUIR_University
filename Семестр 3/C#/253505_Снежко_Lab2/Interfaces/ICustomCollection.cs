﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Interfaces
{
    internal interface ICustomCollection<T> : IEnumerable<T>
    {
        T this[int index] { get; set; }
        void Reset();
        void Next();
        T Current();
        int Counnt { get; }
        void Add(T item);
        void Remove(T item);
        T RemoveCurrent();
    }
}

using System;
using System.Windows.Input;
using Xamarin.Essentials;
using Xamarin.Forms;

namespace homepage.ViewModels
{
    public class AboutViewModel : BaseViewModel
    {
        public AboutViewModel()
        {
    
        }

        public ICommand OpenWebCommand { get; }

    }
}
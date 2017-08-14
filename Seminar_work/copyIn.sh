semdir="/media/sf_Shared_Folder/School/Semestr2/PA2/Seminar_work"
inputdir="/media/sf_Shared_Folder/School/Semestr2/PA2/Seminar_work/src"
netdir="/media/sf_Shared_Folder/NetBeans_Projects/MyRPG"

cd $inputdir
rm *.h *.cpp

cd $netdir
cp *.cpp $inputdir
cp *.h $inputdir

cd $semdir
make clean

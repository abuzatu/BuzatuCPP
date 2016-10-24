rm -f *~
rm -f \#*
rm -f *.tgz
#for each folder in our package, remove the *~ files
for dir in ./*/
do
    dir=${dir%*/}
    folder=${dir##*/}
    echo $folder
    rm -f $folder/*~
    rm -f $folder/a.out
    rm -f $folder/*.exe
done
# end for loop

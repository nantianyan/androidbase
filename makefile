SUBDIRS = sysbase mediabase

.PHONY: all  
all:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		echo "make in $$subdir";\
		cd $$subdir && $(MAKE) && cd -;\
	done 

.PHONY: clean  
clean:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		echo "make clean in $$subdir";\
		cd $$subdir && $(MAKE) clean && cd -;\
	done
